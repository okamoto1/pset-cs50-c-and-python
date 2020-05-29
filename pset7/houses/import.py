import csv
import sys
import re
from cs50 import SQL

if len(sys.argv) != 2:
    print("Error !")
    exit(1)
else:
    open(f'students.db', 'w').close()
    db = SQL("sqlite:///students.db")
    db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            m = re.split(' ', row['name'])
            if len(m) == 2:
                db.execute('INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)',
                m[0], m[1], row['house'], row['birth'])
            else:
                db.execute('INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)',
                m[0], m[1], m[2], row['house'], row['birth'])
    exit(0)
