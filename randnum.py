import random
value=random.randint(1,11)

name = input("Hello, what is your name? ")
print("Hello "+name+". Let's play a game! I will choose a random number from 1-10 and you will have to guess it in 3 turns. Let's begin!")

game()

def game():
    print("Go ahead and take your guess!")
    guesses_left=3
    while guesses_left > 0:
        
        guesses_left = guesses_left -1
        
        guess = input()
        guess=int(guess)
        
        print(f"You have {guesses_left} guesses left.")
        
        if guess == 69420: #cheat code
            print(f"The answer is {value}")
        elif guess == value:
            print("Congrats, you have guessed my number!")
            print("You've won the game! Would you like to play again?")
            win=input()
            if win in ("yes","yep","y","yea","yeap","yeah"):
              game()
            else:
                break
        elif guess < 1 or guess > 10:
            print("I told you my number is from 1-10. Please try a little harder!")
        elif guess > value:
            print("Your guess was too high!")
        elif guess < value:
            print ("Your guess was too low!")
    if guess != value:
        print("Sorry! You've lost the game. Would you like to try again?")
        again = input()
        if again in ("yes","yep","y","yea","yeap","yeah"):
            game()
print("Alright, goodbye!")
