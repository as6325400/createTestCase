import sys

n = int(0)

with open(sys.argv[1], "r") as f:
    n = int(f.readline().strip())

sys.stdout.flush()
count = 0

for i in sys.stdin:
    count += 1
    ans = i.split()
    if len(ans) > 2:
        sys.stderr.write("missing some output") 
        exit(42)
    try:
        num = int(ans[1])
    except:
        sys.stderr.write("user outpu t is not a number") 
        exit(42)
    if ans[0] == "?":
        if num > n:
            print(1)
        elif num <= n:
            print(0)
        sys.stdout.flush()
    elif ans[0] == "!":
        if num == n:
            exit(43)
        else:
            exit(42)
    else:
        sys.stderr.write("Invalid interaction")
        exit(42)
    if count >= 50:
        sys.stderr.write("guess more times")
        exit(42)
