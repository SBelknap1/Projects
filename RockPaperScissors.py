# Define the possible choices
choices = ["rock", "paper", "scissors"]

# Start the game loop
while True:
    # Ask the player to input their choice
    player_choice = input("Choose rock, paper, or scissors: ").lower()
    
    # Validate player input
    if player_choice not in choices:
        print("Invalid choice. Please choose again.")
        continue
    
    # Generate the computer's random choice
    import random
    computer_choice = random.choice(choices)
    
    # Display the choices
    print(f"You chose {player_choice}, computer chose {computer_choice}.")
    
    # Determine the outcome
    if player_choice == computer_choice:
        print("It's a draw!")
    elif (player_choice == "rock" and computer_choice == "scissors") or \
         (player_choice == "paper" and computer_choice == "rock") or \
         (player_choice == "scissors" and computer_choice == "paper"):
        print("You win!")
    else:
        print("You lose!")
    
    # Ask if the player wants to play again
    play_again = input("Do you want to play again? (yes/no): ").lower()
    if play_again != "yes":
        print("Thanks for playing!")
        break
