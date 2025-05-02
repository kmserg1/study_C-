// a) Начнем с того, что переделаем Card из структуры в класс. Хорошей новостью является то, что класс Card очень похож на
// класс Monster из предыдущего задания. Алгоритм действий следующий:
//  Во-первых, переместите перечисления CardSuit и CardRank внутрь класса Card под спецификатор доступа public (они
// неотъемлемо связаны с Card, поэтому должны находиться внутри класса).
//  Во-вторых, создайте закрытые переменные-члены m_rank и m_suit для хранения значений CardRank и CardSuit.
//  В-третьих, создайте открытый конструктор класса Card с инициализацией карт (переменных-членов класса). Укажите
// параметры по умолчанию для конструктора (используйте MAX_RANKS и MAX_SUITS).
//  Наконец, переместите функции printCard() и getCardValue() внутрь класса под спецификатор доступа public (не забудьте
// сделать их const!).

Примечание: При использовании std::array (или std::vector), где элементами являются объекты класса, класс должен иметь
конструктор по умолчанию, чтобы элементы могли быть инициализированы разумными значениями по умолчанию. Если
вы этого не сделаете, топ олучите ошибку попытки ссылаться на удаленную функцию.
Следующий фрагмент кода должен скомпилироваться без ошибок:



#include <iostream>
#include <array>
#include <ctime>// для time()
#include <cstdlib>// для rand() и srand()

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0); // используем static, так как это значение нужно вычислить единожды
	// Равномерно распределяем вычисление значения из нашего диапазон
	return static_cast<int>(rand() * fraction * (max-min+ 1)+min);
}

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
		RANK_4,
		RANK_3,
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
		std::cout << "--- printCard ---\t";
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
public:
	Deck(){
 		for(int suit = 0;suit <MAX_SUITS; ++suit)
		     	for(int rank = 0; rank < MAX_RANKS; ++rank)
 			{
 				m_deck[suit+rank].suit = static_cast<CardSuit>(suit);
	 			deck[suit+rank].rank = static_cast<CardRank>(rank);
 				++card;
 			}
		}
};


int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
	const Card cardQueenHearts(Card::RANK_QUEEN, Card::SUIT_HEART);
	cardQueenHearts.printCard();
	std::cout << " has the value " << cardQueenHearts.getCardValue() << '\n';

	return 0;
}


/*
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
	RANK_4,
	RANK_3,
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

struct Card
{
	CardRank rank;
	CardSuit suit;
};

void printCard(constCard &card)
{
	switch (card.rank)
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
		caseRANK_JACK: std::cout<< 'J'; break;
		case RANK_QUEEN: std::cout<< 'Q'; break;
		caseRANK_KING: std::cout<< 'K'; break;
		caseRANK_ACE: std::cout<< 'A'; break;
	}

	switch (card.suit)
	{
		case SUIT_CLUB: std::cout << 'C'; break;
		case SUIT_HEART: std::cout<< 'H'; break;
		case SUIT_DIAMOND: std::cout<< 'D'; break;
		case SUIT_SPADE: std::cout<< 'S'; break;
	}
}

void printDeck(conststd::array<Card,52>deck)
{
	for(constauto &card : deck)
	{
		printCard(card);
		std::cout <<'';
	}

	std::cout <<'\n';
}

void swapCard(Card&a,Card &b)
{
	Card temp = a;
	a=b;
	b=temp;
}
// Генерируем случайное число между min и max (включительно).

// Предполагается, что srand() уже был вызван
int getRandomNumber(int min, int max)
{
	static constdouble fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0); // используем static, так как это значение нужно вычислить единожды
	// Равномерно распределяем вычисление значения из нашего диапазон
	return static_cast<int>(rand() * fraction * (max-min+ 1)+min);
}

void shuffleDeck(std::array<Card,52>&deck)
// Перебираем каждуюкарту в колоде
{
	for(int index=0; index<52;++index)
	{
		// Выбираем любую случайную карту
		int swapIndex = getRandomNumber(0, 51);
		// Меняем местами с нашей текущей картой
		swapCard(deck[index],deck[swapIndex]);
	}
}

int getCardValue(constCard &card)
{
 	switch (card.rank)
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

 char getPlayerChoice()
 {
 	std::cout <<"(h) tohit,or (s) tostand:";
 	char choice;
 	do
 	{
 		std::cin>> choice;
	 } while (choice !='h' && choice !='s');
 return choice;

 }

 bool playBlackjack(conststd::array<Card,52> deck
 {
 	const Card *cardPtr = &deck[0];

 	int playerTotal = 0;
 	int dealerTotal = 0;

 	// Дилер получает одну карту
 	dealerTotal +=getCardValue(*cardPtr++);
 	std::cout <<"The dealer isshowing: " << dealerTotal << '\n'

 	// Игрокполучает две карты
 	playerTotal +=getCardValue(*cardPtr++);
 	playerTotal +=getCardValue(*cardPtr++);

 	// Игрок начинает
 	while(1)
 	{
 		std::cout <<"You have:"<< playerTotal<< '\n'
 		charchoice = getPlayerChoice();
 		if (choice== 's')
 			break;

 		playerTotal +=getCardValue(*cardPtr++);

 		// Смотрим, не проиграл ли игрок
 		if (playerTotal > 21)
 			return false;
 	}

 	// Если игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
 	while(dealerTotal<17)
 	{
 		dealerTotal +=getCardValue(*cardPtr++);
 		std::cout << "The dealer now has:" << dealerTotal << '\n';
 	}

 	// Если у дилера больше 21, то он проиграл, а игрок выиграл
 	if (dealerTotal > 21)
 		return true;

 	return (playerTotal > dealerTotal);
 }

 int main()
 {
 	srand(static_cast<unsigned int>(time(0)));// используем системные часы в качестве стартового значения
 	rand(); //пользователям VisualStudio: делаем сброс первого случайного числа

 	std::array<Card,52>deck;

 	// Конечно, можно было бы инициализировать каждую карту отдельно, но зачем? Ведь есть циклы!
 	int card=0;
 	for(intsuit = 0;suit <MAX_SUITS; ++suit)
     	for(intrank = 0;rank <MAX_RANKS; ++rank)
 		{
 			deck[card].suit = static_cast<CardSuit>(suit);
 			deck[card].rank = static_cast<CardRank>(rank);
 			++card;
 		}

 	shuffleDeck(deck);

 	if (playBlackjack(deck))
 		std::cout <<"You win!\n";
 	else
 		std::cout <<"You lose!\n";

 	return 0;
 }
*/