import os, sys

_, f1, f2, gen, iters = sys.argv
os.system(f'g++ -o good {f1}')
os.system(f'g++ -o bad {f2}')

for i in range(int(iters)):
    print('Test', i + 1)
    os.system(f'python {gen} > test.txt')
    v1 = os.popen('good < test.txt').read()
    v2 = os.popen('bad < test.txt').read()
    if v1 != v2:
        print("Wrong answer on test:")
        print(open("test.txt").read())
        print(f"Output of {f1}:")
        print(v1)
        print(f"Output of {f2}")
        print(v2)
        break
