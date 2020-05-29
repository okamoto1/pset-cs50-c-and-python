from cs50 import get_string

def main():
    text = get_string("Text: ")
    palavras, letras, periodo = 1, 0, 0
    for char in text:
        if 'a' <= char.lower() and char.lower() <= 'z':
            letras = letras + 1
        elif char == ' ':
            palavras = palavras + 1
        elif char =='?' or char =='.' or char =='!':
            periodo = periodo + 1
    L = (letras / palavras) * 100
    S = (periodo / palavras) * 100
    index = (0.0588 * L) - (0.296 * S) - 15.8;
    if int(round(index)) <= 1:
        print("Before Grade 1")
    elif int(round(index)) >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {int(round(index))}")

main()