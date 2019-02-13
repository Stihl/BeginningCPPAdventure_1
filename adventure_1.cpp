#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>


//special methods std::to_string(x)

int main(){


    //declaring player and enemy attributes, along with rands for match round numbers and and random enemy type
    int x = 1, player_health = 10, attack, block, enemy_health, enemy_attack, enemy_block, enemy_rand, match_rand;
    //Sets up time for the sleep
    unsigned int miliseconds = 3000;
    //Players choice for holding the game
    std::string playerChoice = "";

    //declaring the possible enemy types
    std::string enemies[3] = {"ghoul", "goblin", "gangster"};
    std::string enemy_type = "";

    //seeding the random number generator with the current date time
    srand(time(0));
    
    //Greeting player
    std::cout << "Welcome to the land of Banvalza" << std::endl;

    //setting up the enemy
    enemy_rand = rand() % 3;
    enemy_type = enemies[enemy_rand];
    std::cout << "You encountered a " << enemy_type << std::endl;
    enemy_health = rand() % 10 + 1;

    //Setting up the match
    match_rand = rand() % 8 + 4;
    std::cout << "\n";
    
    while(x < match_rand && player_health > 0){
        //Round start
        x++;
        //if player health is 3 or lower then offer to visit the doctor
        if(player_health <= (player_health/4) + 1){
            int rand_doc;
            std::cout << "Would you like to visit the doctor this round? ('yes' or 'no'): ";
            std::cin >> playerChoice;
            //Generate the random regardless if they want to or not
            rand_doc = rand() % 6 + 1;
            if(playerChoice == "yes"){
                //Player is healed and the round is skipped
                player_health += rand_doc;
                std::cout << "\nThe doctor healed you for " << rand_doc << " hp." << std::endl;
                continue;
            }else{
                //player wasnt healed and continues to battle in rough shape
                std::cout << "\nToo bad... you missed out on " << rand_doc << " hp." << std::endl;
            }

        }

        //Generating random attack and block values for both the player and enemy
        enemy_attack = rand() % 5;
        enemy_block = rand() % 5;
        attack = rand() % 5;
        block = rand() % 5;
        
        Sleep(2000);
        //Player swings their sword.
        std::cout << "You swing your sword for " << std::to_string(attack) << " damage" << std::endl;
        Sleep(miliseconds/2);

        //player attack is blocked by the enemy.
        if(enemy_block >= attack){
            std::cout << "The " << enemy_type << " blocked your attack, now they are preparing to strike!" << std::endl;
        }else{
            //Player attack successfully hit enemy.
            std::cout << "The " << enemy_type << " took " << std::to_string(attack - enemy_block) << " damage" << std::endl;
            enemy_health -= (attack - enemy_block);

            //Enemy died from their wounds.
            if(enemy_health <= 0){
                std::cout << "\nCongratulations you defeated the " << enemy_type << "!\n You win!" << std::endl; 
                break;
            }
        }

        //Lets the player know the enemy is attacking.
        Sleep(miliseconds/2);
        std::cout << "The " << enemy_type <<" strikes back!" << std::endl;
        Sleep(miliseconds/2);

        //Enemies turn to attack.
        if(block >= enemy_attack){
            //Player successfully blocked.
            std::cout << "You blocked the attack, you are unscathed!" << std::endl;
        }else{
            //Player failed to block all the damage.
            std::cout << "The " << enemy_type << " hit you for " << std::to_string(enemy_attack - block) << " damage" << std::endl;
            player_health -= (enemy_attack - block);

            //Player died from their wounds.
            if(player_health <= 0){
                std::cout << "\nOh no, you died, Game Over!" << std::endl;
                break;
            }
        }
        Sleep(miliseconds/2);

        //summary of round
        std::cout << "You have " << std::to_string(player_health) << " Health left" << std::endl;
        std::cout << "From what you can tell the " << enemy_type << " should have " << std::to_string(enemy_health) << " health left." << std::endl; 
        std::cout << "\n";
    }

    //Draw condition, ran out of turns
    if(player_health > 0 && enemy_health > 0){
        if(player_health > enemy_health){
            std::cout << "The " << enemy_type << " left, he must have noticed your combat prowess and decided to leave you alone." << std::endl;
        } else if(player_health < enemy_health){
            std::cout << "The " << enemy_type << " left, he must have found something better to do." << std::endl;
        } else{
            std::cout << "The " << enemy_type << " left, i wonder why he gave up.." << std::endl;
        }
        
    }
    
    //Waits for player to enter something before quitting
    std::cout << "\n\ninput something to quit." << std::endl;
    std::cin >> playerChoice;

}

