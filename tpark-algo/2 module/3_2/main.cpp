/*
 * Современники
 * Ограничение времени	0.05 секунд
 * Ограничение памяти	64Mb
 * Ввод	стандартный ввод или input.txt
 * Вывод	стандартный вывод или output.txt
 *
 * Группа людей называется современниками если был такой момент, когда они могли собраться вместе.
 * Для этого в этот момент каждому из них должно было уже исполниться 18 лет, но ещё не исполниться 80 лет.
 * Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников.
 * В день 18летия человек уже может принимать участие в собраниях, а в день 80летия и в день смерти уже не может.
 * Замечание! Человек мог не дожить до 18-летия, либо умереть в день 18-летия. В этих случаях принимать участие в собраниях он не мог.
 * Пример
 * Ввод
 * 3
 * 2 5 1980 13 11 2055
 * 1 1 1982 1 1 2030
 * 2 1 1920 2 1 2000
 *
 * */

#include <iostream>
#include <cmath>
#include <vector>

#define YEARS_80 29200
#define YEARS_18 6570
#define DAYS_IN_MONTH 30
#define DAYS_IN_YEAR 365


enum typeOfEvent {
    GROUWTH,
    AGING
};

struct event {

    int timestamp;
    typeOfEvent type;

    event(int input_tstamp, typeOfEvent input_type) : timestamp(input_tstamp), type(input_type) {};

    event() : timestamp(0), type(GROUWTH) {};

};

class Comparator {
public:
    bool operator()(const event &l,const event &r) {
        return l.timestamp < r.timestamp;
    }
};

class Human {
private:

    enum stateOfDateLine {
        DAYS,
        MONTHS,
        YEARS
    };

private:
    int adult_timestamp = -1;
    int aged_timestamp = -1;
    bool couldParticipate = true;

    std::pair<int, int> parseLine(std::string dateLine);

public:
    explicit Human(const std::string &birthAndDeath);

    bool sometimeParticipate() { return couldParticipate; }

    int getGrouthTimeStamp() { return adult_timestamp; }

    int getAgingTimeStamp() { return aged_timestamp; }
};

std::pair<int, int> Human::parseLine(std::string dateLine) {

    stateOfDateLine state = DAYS;
    std::pair<int, int> result = {-1, -1};

    std::string tempValue = "";
    int tempResult = 0;

    for (auto ch : dateLine) {
        if (ch == ' ') {
            switch (state) {
                case DAYS: {
                    tempResult += stoi(tempValue);
                    state = MONTHS;
                    break;
                }
                case MONTHS: {
                    tempResult += stoi(tempValue) * DAYS_IN_MONTH;
                    state = YEARS;
                    break;
                }
                case YEARS: {
                    tempResult += stoi(tempValue) * DAYS_IN_YEAR;

                    if (result.first == -1) {
                        result.first = tempResult;
                    } else {
                        result.second = tempResult;
                    }

                    tempResult = 0;
                    state = DAYS;
                    break;
                }
            }
            tempValue = "";
        } else {
            tempValue += ch;
        }
    }
    return result;
}

Human::Human(const std::string &birthAndDeath) {

    std::pair<int, int> birthAndDeathTimeStamps = parseLine(birthAndDeath + " ");

    this->adult_timestamp = birthAndDeathTimeStamps.first + YEARS_18;

    if (birthAndDeathTimeStamps.second > adult_timestamp) {
        this->aged_timestamp = std::min(birthAndDeathTimeStamps.second, birthAndDeathTimeStamps.first + YEARS_80) - 1;
    } else {
        couldParticipate = false;
    }

}


template<typename T, class Compare>
void siftDown(T *array, int count, int index, Compare cmp) {

    int max = index;
    int leftChildIndex = index * 2 + 1;
    int rightChildIndex = index * 2 + 2;

    if (leftChildIndex < count && cmp(array[index], array[leftChildIndex]))
        max = leftChildIndex;


    if (rightChildIndex < count && cmp(array[max], array[rightChildIndex]))
        max = rightChildIndex;

    if (max != index) {
        std::swap(array[max], array[index]);
        siftDown(array, count, max, cmp);
    }
}

template<typename T, class Compare>
void heapSort(T *array, size_t size, Compare cmp) {

    int n = static_cast<int>(size);

    for (int i = n / 2 - 1; i >= 0; --i)
        siftDown(array, n, i, cmp);

    for (int i = n - 1; i >= 0; --i) {
        std::swap(array[0], array[i]);
        siftDown(array, i, 0, cmp);
    }
}


int findContemporaries(std::vector<event> events) {

    int max = 1;
    int counter = 0;

    for (auto i : events) {
        i.type == GROUWTH ? counter++ : counter--;
        if (counter > max)
            max = counter;
    }

    return max;
}

int main() {

    int count;
    std::cin >> count;

    std::vector<event> events;

    std::cin.ignore();
    for (; count > 0; --count) {

        std::string dates;
        std::getline(std::cin, dates);

        Human pretender(dates);

        if (pretender.sometimeParticipate()) {
            events.push_back(event(pretender.getGrouthTimeStamp(), GROUWTH));
            events.push_back(event(pretender.getAgingTimeStamp(), AGING));
        }
    }

    heapSort(events.data(), events.size(), Comparator());

    std::cout << findContemporaries(events);

//    for (auto &event : events)
//        delete event;

    return 0;
}
