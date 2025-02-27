#include <iostream>
#include <vector>

#include "hutils.h"

using namespace hUtils::Text;

struct Humanoid {
    std::string name = "hexagonny";
    std::string charClass = "Thief";
    char rank = 'D';
    std::vector<std::string> items = {"Empty Flask", "Rusty Dagger", "Worthless stick",
                                      "Sword", "Shield", "Health Potion", "Bow", "Arrow",
                                      "Magic Scroll", "Helmet", "Armor", "Boots", "Ring",
                                      "Torch", "Rope", "Pickaxe", "Mana Potion"};
};

void itemListMenu(){
    Humanoid player;

    toLine();
    toCentered("Inventory", 93);
    for(int i = 0; i < player.items.size(); i++){
        toLeft(player.items[i], {}, {}, i + 1);
    }
    toLine();
}

void itemPaginatedMenu(){
    Humanoid player;
    const int PAGE_LIMIT = 5;
    int totalItems = player.items.size();
    int totalPages = (totalItems + PAGE_LIMIT - 1) / PAGE_LIMIT;
    int currentPage = 1;
    char choice;

    do{
        clearAll();
        
        toLine();
        toCentered("Inventory (Page " + std::to_string(currentPage) +
                   " of " + std::to_string(totalPages) + ")", 93);

        int start_index = (currentPage - 1) * PAGE_LIMIT;
        int end_index = (start_index + PAGE_LIMIT < totalItems) ? (start_index + PAGE_LIMIT) : totalItems;

        for (int i = start_index; i < end_index; i++) {
            toLeft(player.items[i], {}, {}, i + 1);
        }

        std::cout<<'\n';
        toCentered("[N] Next Page | [P] Previous Page | [E] Exit");
        std::cout<< color(93) + "Choose: " + defaultText();
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n' && currentPage < totalPages) {
            currentPage++;
        } else if (choice == 'p' && currentPage > 1) {
            currentPage--;
        }
    }while(choice != 'e');
}

void infoMenu(){
    Humanoid player;

    toLine();
    toCentered("Player Info", 93);
    toLeft("Name: "  + player.name      + '\n' +
           "Class: " + player.charClass + '\n' +
           "Rank: "  + player.rank              );
    toLine();

}