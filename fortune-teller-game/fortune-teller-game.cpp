//
// Created by amar on 9/6/26.
//
#include <iostream>
#include <ctime>
#include <print>
#include <vector>

int main() {
    std::srand(std::time(0));

    std::vector<std::string> prediction = {
        "A great opportunity will find you when you least expect it.",
        "Someone from your past will soon bring unexpected news.",
        "Your hard work will finally begin to pay off.",
        "A journey you take will lead to something much more important than you imagined.",
        "Trouble is approaching. Think carefully before making your next move.",
        "Be careful with your next decision — it may change your path.",
        "You may soon lose something that you thought was secure.",
        "Someone you trust will remember your kindness only when they need something from you.",
        "The answer you've been searching for will appear when you stop looking for it.",
        "Your future contains a loss you cannot prevent.",
        "Everything you've built may disappear because of one mistake."
    };

    bool end {false};

    std::string name;

    std::print("Welcome, seeker of fate.\nThe future is hidden, but it is not silent. Within these mysterious predictions lie possibilities of love, success, loss, opportunity, and perhaps even misfortune.\n\nAsk the fortune teller your question, and let fate choose your answer. But remember... you may not always like what the future has in store.");

    std::cout << "\n\nYour name: ";
    std::getline(std::cin, name);

    while (!end) {
        std::cout << "\nVery well, " << name << " the threads of fate have spoken. What I see is...";

        size_t rand_number = static_cast<size_t>((std::rand() % prediction.size()));

        std::cout << prediction[rand_number] << std::endl;
        std::cout << "\nWill you tempt destiny once more? (Y | N): ";

        char goOn;
        std::cin >> goOn;
        end = ((goOn == 'Y') || (goOn == 'y')) ? false : true;
    }
}