/*
c) Теперь нам нужен способ отследить то, какая карта будет раздаваться следующей (в исходной программе для этого
используется cardptr):

 Во-первых, добавьте в класс Deck целочисленный член m_cardIndex и инициализируйте его значение 0. 
  m_cardIndex будет содержать номер текущей (верхней, значения от 52 до 1) карты в колоде.

 Во-вторых, создайте открытый метод dealCard(), который будет возвращать константную ссылку на текущую карту и
  увеличивать m_cardIndex.

 В-третьих, метод shuffleDeck() также должен быть обновлен для сброса m_cardIndex (так как после перетасовки колоды,
  раздается карта, которая является верхней).
*/

#include <iostream>
#include <array>
#include <ctime>// для time()
#include <cstdlib>// для rand() и srand()
#include <cassert>// для assert

class Card{
public:
	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};

	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};
private:
	CardRank m_ranc;
	CardSuit m_suit;

public:
	Card(CardRank r=static_cast<CardRank>(MAX_RANKS-1), CardSuit s=static_cast<CardSuit>(MAX_SUITS-1)):
		m_ranc{r},m_suit{s}
	{
	}

	void printCard() const
	{
		std::cout << "--- printCard ---\n";
		std::cout << "m_ranc=" << m_ranc << ' ';
		switch (m_ranc)
		{
			case RANK_2: std::cout<< '2'; break;
			case RANK_3: std::cout<< '3'; break;
			case RANK_4: std::cout<< '4'; break;
			case RANK_5: std::cout<< '5'; break;
			case RANK_6: std::cout<< '6'; break;
			case RANK_7: std::cout<< '7'; break;
			case RANK_8: std::cout<< '8'; break;
			case RANK_9: std::cout<< '9'; break;
			case RANK_10: std::cout<< 'T'; break;
			case RANK_JACK: std::cout<< 'J'; break;
			case RANK_QUEEN: std::cout<< 'Q'; break;
			case RANK_KING: std::cout<< 'K'; break;
			case RANK_ACE: std::cout<< 'A'; break;
		}
		std::cout << '\t';
		std::cout << "m_suit=" << m_suit << ' ';
		switch (m_suit)
		{
			case SUIT_CLUB: std::cout << 'C'; break;
			case SUIT_HEART: std::cout<< 'H'; break;
			case SUIT_DIAMOND: std::cout<< 'D'; break;
			case SUIT_SPADE: std::cout<< 'S'; break;
		}
		std::cout << '\n';
	}

	int getCardValue() const
	{
 		switch (m_ranc)
	 	{
 			case RANK_2: return 2;
 			case RANK_3: return 3;
			case RANK_4: return 4;
 			case RANK_5: return 5;
 			case RANK_6: return 6;
	 		case RANK_7: return 7;
 			case RANK_8: return 8;
 			case RANK_9: return 9;
			case RANK_10: return 10;
 			case RANK_JACK: return 10;
 			case RANK_QUEEN: return 10;
			case RANK_KING: return 10;
 			case RANK_ACE: return 11;
	 	}

 	return 0;
	}

};

class Deck{
private:
	std::array<Card,52> m_deck;
	int m_cardIndex {0};

	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0); // используем static, так как это значение нужно вычислить единожды
		// Равномерно распределяем вычисление значения из нашего диапазон
		return static_cast<int>(rand() * fraction * (max-min+ 1)+min);
	}

	
	void swapCard(Card &a, Card &b)
	{
		Card temp = a;
		a=b;
		b=temp;
	}

public:
	Deck(){
		// заполнить массив картами и перемешать
		consec_fill();
		shuffleDeck();
	}

	void consec_fill(){
		for(int i=0; i<52; ++i){
			m_deck[i] = Card(static_cast<Card::CardRank>(i % Card::MAX_RANKS), static_cast<Card::CardSuit>(i % Card::MAX_SUITS));
		}
	}


	void shuffleDeck(){
		//перемешиваем карты
		for(int index=0; index<52;++index)
		{
			// Выбираем любую случайную карту
			int swapIndex = getRandomNumber(0, 51);
			// Меняем местами с нашей текущей картой
			swapCard(m_deck[index],m_deck[swapIndex]);
		}
	m_cardIndex=0;
	}

	const Card& dealCard() {
		assert (m_cardIndex < 52);
		return m_deck[m_cardIndex++];	
	}

	void printDeck() const
	{
		for(auto &card : m_deck)
		{
			card.printCard();
			std::cout <<'\n';
		}

		std::cout <<'\n';
	}

};


char getPlayerChoice()
{
	std::cout << "(h) to hit (взять), or (s) to stand (стоять): ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');
	
	return choice;
}

bool playBlackjack(Deck& deck)
{
 
	int playerTotal = 0;
	int dealerTotal = 0;
 
	// Дилер получает одну карту
	
//	dealerTotal += deck[deck.dealCard()].getCardValue();
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';
 
	// Игрок получает две карты
//	playerTotal += deck[deck.dealCard()].getCardValue();
//	playerTotal += deck[deck.dealCard()].getCardValue();
 
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	// Игрок начинает
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;
 
		playerTotal += deck.dealCard().getCardValue();
		
		// Смотрим, не проиграл ли игрок
		if (playerTotal > 21)
			return false;
	}
 
	// Если игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}
 
	// Если у дилера больше 21, то он проиграл, а игрок выиграл
	if (dealerTotal > 21)
		return true;
 
	return (playerTotal > dealerTotal);
}


int main()
{
	srand(static_cast<unsigned int>(time(0))); //используем системныечасы вкачестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первогослучайного числа

	Deck deck;
	deck.shuffleDeck();
	
	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";
 
	return 0;

}
