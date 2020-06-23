Name:
ID:
Email:
WorkID: cp264a2
Statement: I claim that the enclosed submission is my individual work 

Check list, self-evaluation/marking, marking scheme:
Note: fill self-evaluation for each of the following brackets. The field format is [self-evaluation / total marks / marker's evaluation]. For example, you put your self-evaluation, say 2, like [2/2/]. If marker gives different evaluation value say 1, it will show [2/2/1] in the marking report. 

Evaluation: [self-evaluation/total/marker-evaluation]

Q1
1. correctness of iterative_fibonacci     [3/3/]
2. correctness of recursive_fibonacci     [3/3/]
3. main function and testing              [4/4/]

Q2
1. correctness of honor's algorithm       [5/5/]
2. main function                          [3/3/]  
3. evaluation & testing                   [2/2/]

Q3
1. horner function                        [3/3/]
2. bisection function                     [4.5/5/]
3. robustness	                          [2/2/]

Total:                                 [29.5/30/]


Test result:
Q1 output: (copy the screen output of your test run) 
Iterative algorithm measurement:
iterative_fibonacci(40): 102334155
high address: 4294953924
low address: 4294953872
memory span: 52
time_span(iterative_fibonacci(40) for 500000 times): 62.0 (ms)

Recursive algorithm measurement:
iterative_fibonacci(40): 102334155
high address: 4294953924
low address: 4294951376
memory span: 2548
time_span(recursive_fibonacci(40) for 10 times): 7907.0 (ms)

Comparison of recursive and iterative algorithms:
memory_span(recursive_fibonacci(40))/memory_span(iterative_fibonacci(40)): 49.0
time_span(recursive_fibonacci(40))/time_span(iterative_fibonacci(40)): 6376612.9

Q2 output: (copy the screen output of your test run) 
Please enter x value (Ctrl+C or 999 to quit):
0
1.0*0.0^3 + 2.0*0.0^2 + 3.0*0.0^1 + 4.0*0.0^0 = 4.0
Please enter x value (Ctrl+C or 999 to quit):
1
1.0*1.0^3 + 2.0*1.0^2 + 3.0*1.0^1 + 4.0*1.0^0 = 10.0
Please enter x value (Ctrl+C or 999 to quit):
2
1.0*2.0^3 + 2.0*2.0^2 + 3.0*2.0^1 + 4.0*2.0^0 = 26.0
Please enter x value (Ctrl+C or 999 to quit):
10
1.0*10.0^3 + 2.0*10.0^2 + 3.0*10.0^1 + 4.0*10.0^0 = 1234.0
Please enter x value (Ctrl+C or 999 to quit):
999

Q3 output: (copy the screen output of your test run) 

f(-2.000000): -2.000000
f(2.000000): 26.000000
root: -1.500000
f(-1.500000): 0.000000

