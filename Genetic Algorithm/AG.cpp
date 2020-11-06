#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <set>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#define ulong unsigned long
#define uint unsigned int

using namespace std;
const ulong population_number = 20;//nombre total de groupe
const ulong times = 50;//Algèbre génétique
const ulong N = 200;
 
int machine;          //Nombre de machines
int job;              //Nombre d'emplois
int process;          //Nombre total de processus
int chromosome_size;  //Longueur du chromosome

const string ins_machine = "Machines.csv";             //entrer la fiche Machine
const string ins_time = "Times.csv";                //entrer la fiche Time
const string res_heuristique = "Heuristique.csv";  //entrer la fiche du résultat heuristique

 
const class Probability {        
public:
    const double cross = 0.95;   //Probabilité de croisement
    const double mutation = 0.05;//Probabilité de mutation
} probability;
 
class Matrix {              //matrice
public:
    int Machine[N][N] = {}; //job process => machine
    int Time[N][N] = {};    //job process => time
    int Process[N][N] = {}; //job machine => process
    Matrix() {
        fill(Machine[0], Machine[0] + N * N, -1);
        fill(Process[0], Process[0] + N * N, -1);
    }
} matrix;
 
class Gene {     
public:
    string chromosome = string(static_cast<ulong>(job * machine), '0'); 
    int fitness = 0;                                                    
 
    explicit Gene(int fitness) { this->fitness = fitness; };
 
    Gene() = default;
 
    Gene(const Gene &other) {
        chromosome = other.chromosome;
        fitness = other.fitness;
    }
 
    Gene &operator=(const Gene &other) = default;
 
    bool operator==(const Gene &other) const {
        return chromosome == other.chromosome && fitness == other.fitness;
    }
 
    bool operator<(const Gene &other) const {
        return chromosome < other.chromosome;
    }
};
 
vector<Gene> populations;       
 
class Store {
public:
    int machineWorkTime[N] = {}; //Temps de travail de la machine
    int processIds[N] = {};      //Processus correspondant à la tâche
    int endTime[N][N] = {};      //job process => endtime
    int startTime[N][N] = {};    //job process => starttime
    Store() = default;
 
    Store(const Store &other) {
        copy(begin(other.machineWorkTime), end(other.machineWorkTime), begin(machineWorkTime));
        copy(begin(other.processIds), end(other.processIds), begin(processIds));
        copy(other.endTime[0], other.endTime[0] + N * N, endTime[0]);
        copy(other.startTime[0], other.startTime[0] + N * N, startTime[0]);
    }
 
    Store &operator=(const Store &other) {
        copy(begin(other.machineWorkTime), end(other.machineWorkTime), begin(machineWorkTime));
        copy(begin(other.processIds), end(other.processIds), begin(processIds));
        copy(other.endTime[0], other.endTime[0] + N * N, endTime[0]);
        copy(other.startTime[0], other.startTime[0] + N * N, startTime[0]);
        return *this;
    }
};
 
/**
 * Générer des nombres aléatoires
 * @param start
 * @param end
 * @return
 */
ulong randint(ulong start, ulong end) {
    return rand() % (end - start + 1) + start;
}
 
/**
 * Générer des nombres aléatoires
 * @param end
 * @return
 */
ulong randint(ulong end) {
    return rand() % (end + 1);
}
 
/**
 * char => int
 * @param ch
 * @return
 */
int Int(char ch) {
    return ch - '0';
}
 
/**
 *int => char
 * @param i
 * @return
 */
char Char(int i) {
    return static_cast<char>(i + '0');
}
 
/**
 * 
 * @param v
 * @param length
 * @param except
 */
void generateVector(vector<int> &v, int length, int except = -1) {
    for (int i = 0; i < length; i++) {
        if (except != -1 && i == except) continue;
        v.push_back(i);
    }
}
 
/**
 * Calculer fitness
 * @param gene
 * @param store
 */
void calculateFitness(Gene &gene, Store &store) {
    int fulfillTime = 0;
    for (char i : gene.chromosome) {
        int jobId = Int(i) - 1,
                processId = store.processIds[jobId],
                machineId = matrix.Machine[jobId][processId],
                time = matrix.Time[jobId][processId];
        store.processIds[jobId]++;
        store.startTime[jobId][processId] = processId == 0 ? store.machineWorkTime[machineId] : max(store.endTime[jobId][processId - 1],       store.machineWorkTime[machineId]);
        store.machineWorkTime[machineId] = store.startTime[jobId][processId] + time;
        store.endTime[jobId][processId] = store.machineWorkTime[machineId];
        if (store.machineWorkTime[machineId] > fulfillTime) {
            fulfillTime = store.machineWorkTime[machineId];
        }
    }
    gene.fitness = fulfillTime;
}

string AtoS(vector<int> arr){
    string res;
    for(int i = 0 ; i < arr.size(); i++){
        char a = arr[i] + '0';
        res += a;
    }
    return res;

}

void readFileResultat(string f, vector<int> &arr){
    ifstream infile;
    infile.open(f);
    if (!infile.is_open())
    {
        cout << "Can't find result of heuristique" << endl;

    }

    string line , number;
    istringstream is(line);
    int p;
    while(std::getline(infile, line))
    {
        istringstream is(line);
        while(std::getline(is, number, ','))
        {
            arr.push_back(stoi(number)) ;
        }

        
    }
    
    

    infile.close();

}
 
/**
 * Population initiale
 * @param genes 
 * @param population 
 */
void initializePopulation(vector<Gene> &genes, int population) {
    set<Gene> gs;
    for (int i = 0; i < population - 1; i++) {
        vector<int> index_list;
        generateVector(index_list, job * machine);
        Gene gene;
        for (int j = 1; j <= job; j++) {
            for (int k = 0; k < machine; k++) {
                ulong index = randint(index_list.size() - 1);
                int value = index_list[index];
                index_list.erase(index_list.begin() + index);
                if (matrix.Process[j - 1][k] != -1)
                    gene.chromosome[value] = Char(j);
            }
        }
        
        remove_if(gene.chromosome.begin(), gene.chromosome.end(), [](char v) -> bool { return v == '0'; });
        gene.chromosome.resize(static_cast<ulong>(chromosome_size));
        Store store;
        calculateFitness(gene, store);
        gs.insert(gene);
    }   
    Gene gene2;
    vector<int> arr;
    readFileResultat(res_heuristique, arr);
    if(arr.size()){ 
    gene2.chromosome = AtoS(arr);

    remove_if(gene2.chromosome.begin(), gene2.chromosome.end(), [](char v) -> bool { return v == '0'; });
    gene2.chromosome.resize(static_cast<ulong>(chromosome_size));
    Store store;
    calculateFitness(gene2,store);
    gs.insert(gene2);  

    insert_iterator<vector<Gene>> insert_vector(genes, genes.begin());
    copy(gs.begin(), gs.end(), insert_vector);
    }
}
 
/**
 * Mutation génétique
 * @param gene 
 * @param n 
 */
void geneticMutation(Gene &gene, int n = 2) {
    vector<int> index_list;
    generateVector(index_list, chromosome_size);
    for (int i = 0; i < n; i++) {
        ulong first = randint(0, index_list.size() - 1);
        index_list.erase(index_list.begin() + first);
        ulong second = randint(0, index_list.size() - 1);
        swap(gene.chromosome[first], gene.chromosome[second]);
    }
    Store store;
    calculateFitness(gene, store);
}
 
/**
 * Croisement de gènes
 * @param first 
 * @param second 
 * @return 
 */
pair<Gene, Gene> orderCrossover(Gene &first, Gene &second) {
    function<Gene(Gene &, Gene &)> generateChild = [](Gene &first, Gene &second) -> Gene {
        vector<int> index_list;
        generateVector(index_list, chromosome_size);
 
        ulong start = randint(0, index_list.size() - 1);
        index_list.erase(index_list.begin() + start);
        ulong end = randint(0, index_list.size() - 1);
 
        string middle = first.chromosome.substr(start, end - start),
                t = middle,
                k = second.chromosome;
        for (char &it : t) {
            for (int i = 0; i < k.size(); i++) {
                if (k[i] == it) {
                    k.erase(k.begin() + i);
                    break;
                }
            }
        }
        Gene child;
        child.chromosome = k.substr(0, start) + middle + k.substr(start, k.length() - start);
        Store store;
        calculateFitness(child, store);
        return child;
    };
    pair<Gene, Gene> child;
    child.first = generateChild(first, second);
    child.second = generateChild(second, first);
    return child;
}
 
/**
 * Sélectionnez des individus
 * @param n 
 * @return 
 */
Gene selectIndividual(int n = 3) {
    vector<int> index_list;
    generateVector(index_list, population_number);
    vector<Gene> simple;
    for (int i = 0; i < n; i++) {
        ulong index = randint(index_list.size() - 1);
        index_list.erase(index_list.begin() + index);
        simple.push_back(populations[index]);
    }
    Gene best_gene(0xffffff);
    for (int i = 1; i < n; i++) {
        if (simple[i].fitness < best_gene.fitness) {
            best_gene = simple[i];
        }
    }
    return best_gene;
}


void readFile(string f,int m[N][N],bool b){
    int i = 0;
    int j = 0;
    ifstream infile;
    infile.open(f);
    if (!infile.is_open())
    {
        cout << "open failed" << endl;
        exit(0);
    }

    string line , number;
    istringstream is(line);
    int p;
    while(std::getline(infile, line))
    {
        istringstream is(line);
        while(std::getline(is, number, ','))
        {
            m[i][j] = stoi(number) ;
            j++;
        }
        if (b){
            p = j;
            chromosome_size += p;
            if (process < p) process = p;
        }
        j=0;
        i++;
    }
    if(b){
        cout << "input job and machine:" << endl;
        cin >> job >> machine;
    }

    infile.close();

}
 
int main() {
    clock_t startTime = clock();
    srand(static_cast<uint>(time(nullptr)));
 
    chromosome_size = 0;
    readFile(ins_machine,matrix.Machine,true); //entrer la fiche Machine
    readFile(ins_time,matrix.Time,false);  

 
    for (int i = 0; i < job; i++) {
        for (int j = 0; j < process; j++) {
            if (matrix.Machine[i][j] != -1)
                matrix.Process[i][matrix.Machine[i][j]] = j;
        }
    }
 
    initializePopulation(populations, population_number);    
    ulong n = times;
    while (n-- > 0) {
        cout << "n = " << n << endl;
        double P = randint(0, 100) / 100.0;
        if (P < probability.mutation) {
            ulong index = randint(populations.size() - 1);
            geneticMutation(populations[index]);
        } else {
            ulong size = populations.size();
            ulong m = size / 4;
            set<Gene> children;
            while (m-- > 0) {
                Gene father = selectIndividual();
                Gene mother = selectIndividual();
                pair<Gene, Gene> child = orderCrossover(father, mother);
                children.insert(child.first);
                children.insert(child.second);
            }
            sort(populations.begin(), populations.end(),
                 [](const Gene &a, const Gene &b) -> bool { return a.fitness < b.fitness; });
            populations.resize(size - size / 4);
            for (const auto &it : children) {
                populations.push_back(it);
            }
            sort(populations.begin(), populations.end());
            auto iter = unique(populations.begin(), populations.end());
            populations.resize(static_cast<ulong>(distance(populations.begin(), iter)));
        }
    }
 
    Gene best_gene(0xffffff);
    for (const auto &it : populations) {
        //cout << "chromosome = " << it.chromosome << " " << it.fitness << endl;Sortie de chaque chromosome
        if (best_gene.fitness > it.fitness) {
            best_gene = it;
        }
    }
 
    Store store;
    string s = best_gene.chromosome;
    string res;
    for(int i = 0; i< s.size(); i++){

        string temp;
        stringstream ss;
        int a = s[i] -'0';
        ss << a;
        temp = ss.str();

        if(i != s.size() - 1){
            temp = temp + "->";
        }
        
        res += temp;

        
    }

  
    calculateFitness(best_gene, store);
    for (int i = 0; i < machine; i++) {
        cout << "machine" << i << " work time " << store.machineWorkTime[i] << endl;
    }
 
    for (int j = 0; j < job; j++) {
        for (int k = 0; k < process; k++) {
            if (matrix.Machine[j][k] != -1)
                cout << "job" << j << " process" << k << " machine" << matrix.Machine[j][k] << " start time="
                     << store.startTime[j][k] << " end time=" << store.endTime[j][k] << endl;
        }
    }
    clock_t endTime = clock();

    cout << "resultat = " << res << endl;
    cout <<"Cmax= " << best_gene.fitness << endl;
    cout<< "Duree du programme " << ":" << double(endTime - startTime)/ CLOCKS_PER_SEC << "s" <<endl;
    
    system("pause");
    return 0;
}