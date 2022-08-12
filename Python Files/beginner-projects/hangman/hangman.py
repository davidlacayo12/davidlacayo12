import random
import string
from words import words 

def get_valid_word(words):
    word=random.choice(words)   #randomly chooses something from the long list of words 
    while '-' in word or ' ' in words:  #makes sure that we choose a word without a space or a hyphen 
        word = random.choice(words)

    return word

def hangman():
    word = get_valid_word(words)
    word_letters = set(word) #letters in word
    alphabet = set(string.ascii_uppercase)
    used_letters = set() #what the user has guessed 

    #getting user input 
    while len(word_letters) > 0:   
        print("You have used these letters: ', ' ".join(used_letters))

        word_list = [letter if letter in used_letters else '-' for letter in word]
        print("Current word: '. ' ".join(word_list))

        user_letter = input("Guess a letter: ").upper()
        if user_letter in alphabet - used_letters:
            used_letters.add(user_letter)
            if user_letter in word_letters:
                word_letters.remove(user_letter)

        elif user_letter in used_letters:
            print("You have already used that character. Please try again.")

        else:
            print("Invalid character. Please try again.")


hangman()