import random

def number_guessing_game():
    print("Welcome to the Number Guessing Game")
    print("I'm thinking of a number between 1 and 100.")

    number = random.randint(1, 100)
    attempts = 0

    while True:
        try:
            guess = int(input("Take a guess: "))
            attempts += 1

            if guess < number:
                print("Too low. Try again.")
            elif guess > number:
                print("Too high. Try again.")
            else:
                print(f" You've guessed the number {number} in {attempts} attempts!")
                break
        except ValueError:
            print("That is not a number bruh. Please enter a number between 1 and 100.")

    print("Thanks for playing")

Run the game
number_guessing_game()
