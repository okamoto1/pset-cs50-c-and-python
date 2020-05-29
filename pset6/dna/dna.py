import csv
import sys
import re

def main():
    if len(sys.argv) != 3:
        print("missing command-line argument")
        exit(1)
    else:
        i = 0
        s, nome = '', ''
        dados = []
        with open(sys.argv[2]) as file:
            seq = file.read()
        with open(sys.argv[1], newline='') as csvfile:
            reader = csv.DictReader(csvfile)
            reader1 = csv.reader(csvfile)
            header = reader.fieldnames
            for row in reader1:
                 dados = dados + row
            while i < len(header) - 1:
                s = s + check(header[i + 1], seq)
                i = i + 1
            teste = ''.join(dados)
            m = re.search(s, teste)
            if m == None:
                print('No match')
            else:
                comeco = m.start()
                while teste[comeco - 1].isalpha() != False:
                    nome = teste[comeco - 1] + nome
                    comeco = comeco - 1
                print(nome)
                
def check(header, seq):
    antigo, tmp, final = 0, 0, 1
    for match in re.finditer(header, seq):
        s = match.start()
        e = match.end()
        if s == antigo:
            tmp = tmp + 1
            if tmp > final:
                final = tmp
        else:
            if tmp > final:
                final = tmp
            tmp = 1
        antigo = e
    return str(final)

    
main()






