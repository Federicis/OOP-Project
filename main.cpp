#include <iostream>
#include <string>

class shop{
private:
    std::string Aici_o_sa_apara_cele_5_carti_pe_care_le_poti_cumpara_din_shop_dupa_ce_implementez_clasele;
public:
    explicit shop(const std::string &aiciOSaAparaCele5CartiPeCareLePotiCumparaDinShopDupaCeImplementezClasele)
            : Aici_o_sa_apara_cele_5_carti_pe_care_le_poti_cumpara_din_shop_dupa_ce_implementez_clasele(
            aiciOSaAparaCele5CartiPeCareLePotiCumparaDinShopDupaCeImplementezClasele) {
        std::cout << "constructor shop\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const shop &shop) {
        os << "Aici_o_sa_apara_cele_5_carti_pe_care_le_poti_cumpara_din_shop_dupa_ce_implementez_clasele: "
           << shop.Aici_o_sa_apara_cele_5_carti_pe_care_le_poti_cumpara_din_shop_dupa_ce_implementez_clasele;
        return os;
    }

    void shuffle() {
        std::cout << "Aici se da reroll la alte carti\n";
    }
};

class player{
private:
    int hp;
    int coins;
public:
    player(int hp, int coins) : hp(hp), coins(coins) {
        std::cout << "constructor player\n";
    }

    player(const player& other): hp(other.hp), coins(other.coins) {
        std::cout << "cc player\n";
    }

    player& operator=(const player& other) {
        hp = other.hp;
        coins = other.coins;
        std::cout << "operator= copiere player\n";
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const player &player) {
        os << "hp: " << player.hp << " coins: " << player.coins;
        return os;
    }

    virtual ~player() {
        std::cout << "destructor player\n";
    }

    void reroll(shop mag){
        if(this->coins >= 1)
        {
            std::cout << "Se da random reroll la alte carti si scadem costul reroll-ului din banii jucatorului\n";
            --this->coins;
            mag.shuffle();
        }
        else
        {
            std::cout << "Esti sarac\n";
        }
    }
    void reset_coins(){
        std:: cout << "Bani inainte de reset: " << this->coins << '\n';
        this->coins = 10;
        std:: cout << "Bani dupa reset: " << this->coins << '\n';
        std::cout << "Bugetul a fost resetat\n";
    }
};

class game{
private:
    int round;
public:
    explicit game(int round) : round(round) {
        std::cout << "constructor meci\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const game &game) {
        os << "round: " << game.round;
        return os;
    }

    void next_round(shop mag, player& first, player& second){
        this->round++;
        mag.shuffle();
        first.reset_coins();
        second.reset_coins();
    }
};

int main() {
    game meci{1};
    shop magazin{""};
    player p1{10, 0}, p2{10, 10};
    std::cout << meci << '\n';
    meci.next_round(magazin, p1, p2);
    for(int i = 1; i <= 11; i++)
    {
        p2.reroll(magazin);
    }
    p1.reroll(magazin);
    std::cout << p1 << '\n';
    meci.next_round(magazin, p1, p2);
    std::cout << meci << '\n';
    return 0;
}
