# -*- coding: utf-8 -*-
import copy
import csv
import time


start = time.time()
with open('Machines.csv') as f:
    reader = csv.reader(f)
    job_list = list(reader)

with open('Times.csv') as f:
    reader = csv.reader(f)
    time_list = list(reader)

processing_list = []
Long = len(job_list[0])
high = len(job_list)
for i in range(1, high+1):
    processing_list += [i] * Long
# print(processing_list)

processing_list1 = list(range(Long*high))
# print(processing_list1)

machine_list = []
for i in job_list:
    machine_list.extend(i)
machine_list = [int(x) for x in machine_list]
# print(machine_list)

processing_time = []
for i in time_list:
    processing_time.extend(i)
processing_time = [int(x) for x in processing_time]
# print(processing_time)
# 求出每道工序的开工时间

initial_start_time = [[] for i in range(len(processing_list))]
initial_start_time[0].append(0)
for i in range(1, len(processing_list)):
    for j in range(0, i):
        if processing_list[j] == processing_list[i]:
            initial_start_time[i].append(processing_time[j])
        else:
            initial_start_time[i].append(0)

for i in range(len(initial_start_time)):
    initial_start_time[i] = sum(initial_start_time[i])

# 求出每个工序的后序工序的加工时间
later_processing_time = [[] for i in range(len(processing_list))]
for i in range(len(processing_list)):
    for j in range(i + 1, len(processing_list)):
        if processing_list[j] == processing_list[i]:
            later_processing_time[i].append(processing_time[j])
        else:
            later_processing_time[i].append(0)
for i in range(len(later_processing_time)):
    later_processing_time[i] = sum(later_processing_time[i])

later_process_num = [[] for i in range(len(processing_list))]
for i in range(len(processing_list)):
    for j in range(i + 1, len(processing_list)):
        if processing_list[j] == processing_list[i]:
            later_process_num[i].append(1)
        else:
            later_process_num[i].append(0)
for i in range(len(later_process_num)):
    later_process_num[i] = sum(later_process_num[i])

# 工序排序
initial_start_time1 = copy.deepcopy(initial_start_time)
later_processing_time1 = copy.deepcopy(later_processing_time)
later_process_num1 = copy.deepcopy(later_process_num)

# 将（p,q,r）与每个工序对应，用字典表示
list1 = list(zip(initial_start_time, later_processing_time, later_process_num))
dict1 = {}
for i in range(len(processing_list1)):
    dict1[processing_list1[i]] = list1[i]

# 根据冒泡排序法对（p,q,r）中的值依次比较大小，并对工序排序
for i in range(len(processing_list1)):
    for j in range(i + 1, len(processing_list1)):
        if dict1[processing_list1[i]][0] > dict1[processing_list1[j]][0]:
            processing_list1[i], processing_list1[j] = processing_list1[j], processing_list1[i]
        elif dict1[processing_list1[i]][0] == dict1[processing_list1[j]][0]:
            if dict1[processing_list1[i]][1] > dict1[processing_list1[j]][1]:
                processing_list1[i], processing_list1[j] = processing_list1[j], processing_list1[i]
            elif dict1[processing_list1[i]][1] == dict1[processing_list1[j]][1]:
                if dict1[processing_list1[j]][2] > dict1[processing_list1[i]][2]:
                    processing_list1[i], processing_list1[j] = processing_list1[j], processing_list1[i]

# print('顺序工序:%s' % processing_list1)
processing_list2 = []
for i in range(len(processing_list)):
    processing_list2.append(processing_list[processing_list1[i]])
# print list1
# print(dict1)

print('Séquence de processus:%s' % processing_list2)
with open("Heuristique.csv", "w", newline='') as csvfile:
    for i in processing_list2:
        csvfile.write(str(i))
        csvfile.write('\n')
# print dict1


# 求出每个工序实际的开工时间以及完工时间
start_time_dict = {}
complete_time_dict = {}
for i in range(len(processing_list1)):
    list1 = []  # 同一个工件每道工序完工时间
    list2 = []  # 同一个机器上所有工序完工时间
    a = 0  # 紧前工序完工时间
    b = 0  # 同一个机器上上一道工序的完工时间
    if i == 0:
        start_time_dict[processing_list1[i]] = 0
        complete_time_dict[processing_list1[i]] = processing_time[processing_list1[i]]
    else:
        for j in range(0, i):
            # 判断当前工序与同一工件前置工序的完工时间和同一个机器上前置工序的完工时间的大小，取两者最大值作为开工时间
            if processing_list2[i] == processing_list2[j]:
                # 是否有紧前工序
                list1.append(complete_time_dict[processing_list1[j]])
            else:
                # 如果没有紧前工序， 判断是否有相同的机器上的前道工序
                list1.append(0)
                if machine_list[processing_list1[i]] == machine_list[processing_list1[j]]:
                    list2.append(complete_time_dict[processing_list1[j]])
                else:
                    list2.append(0)
        a = max(list1)
        b = max(list2)
        start_time_dict[processing_list1[i]] = max(a, b)
        complete_time_dict[processing_list1[i]] = max(a, b) + processing_time[processing_list1[i]]

end = time.time()
print("Cmax est", complete_time_dict[max(complete_time_dict, key=complete_time_dict.get)])
print("dictionnaire de DD", start_time_dict)
print("dictionnaire de DF", complete_time_dict)
print("Running time:", end-start, "S")

