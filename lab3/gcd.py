##Greatest Common Divisor

def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
    

a,b = map(int,input("Enter two numbers:").split())
result = gcd(a,b)

print(f"The greatest common divisor of {a} and {b} is {result}")