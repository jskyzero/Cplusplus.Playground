import random

with open('in', 'w') as f:
    for _ in xrange(1000):
        x = random.randint(1, 100)
        f.write(str(random.randint(1, 10**x)) + '\n')
