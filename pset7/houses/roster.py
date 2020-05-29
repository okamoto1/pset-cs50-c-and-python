import csv
import sys
import re
from cs50 import SQL

if len(sys.argv) != 2:
    print("Error !")
    exit(1)
else:
    open(f'students.db', 'r').close()
    db = SQL("sqlite:///students.db")
    teste = sys.argv[1]
    m = db.execute(f"SELECT first, middle, last AS n , birth FROM students WHERE house = '{teste}' ORDER BY n ASC")
    for i in range(len(m)):
        if m[i]['middle'] == None:
            print(m[i]['first'], m[i]['n'] + ", born", m[i]['birth'], )
        else:
            print(m[i]['first'], m[i]['middle'], m[i]['n'] + ", born", m[i]['birth'])
    exit(0)
    