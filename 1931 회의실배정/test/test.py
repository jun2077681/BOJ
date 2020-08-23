import subprocess
from itertools import combinations

compile1 = 'g++ mycode.cpp -o mycode -O2 -Wall -lm -static -std=gnu++14 -DONLINE_JUDGE -DBOJ'
subprocess.run(compile1.split(), stderr=subprocess.PIPE)

case_num = 12

for case in range(1, case_num + 1):
    with open(f"{case}.in", "r", encoding="utf-8") as input_case:
        txt = input_case.read()
        p = subprocess.run(['./mycode'], stdout=subprocess.PIPE, input = txt, encoding='ascii')
        mycode = p.stdout

        with open(f"{case}.out", "r", encoding="utf-8") as output_case:
            answer = output_case.read()
            if mycode.strip() == answer.strip():
                continue
            else:
                print(f'case {case}')
                print(f'mycode: {mycode.strip()}')
                print(f'answer: {answer.strip()}')
                print('----------------------------------')
                print(txt)
                break

print('finish')
