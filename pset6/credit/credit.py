from cs50 import get_int

def main():
    num = ''
    while len(num) < 10:
        valor = get_int("Number: ")
        num = str(valor)
    check(num)
    
def check(num):
    c, soma = 0, 0
    for i in num[: :-1]:
        n = int(i)
        if c % 2 == 0:
            soma = n + soma
        else:
            n = n * 2
            if n >= 10:
                oi = str(n)
                n = int(oi[1]) + int(oi[0])
            soma = n + soma
        print(soma)
        c = c + 1
    if soma % 10 == 0:
        if c == 15:
            if num[:2] == '34' or num[:2] == '37':
                print("AMEX")
            else:
                print("INVALID")
        elif c == 16:
            if int(num[:2]) >= 51 and int(num[:2]) <= 55:
                print("MASTERCARD")
            elif num[0] == '4':
                print("VISA")
            else:
                print(int(num[:2]))
                print("INVALID")
        elif c == 13:
            if num[0] == '4':
                print("VISA")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")
    
main()