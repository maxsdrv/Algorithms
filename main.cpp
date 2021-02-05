#include "libraries.h"


using namespace std;


const auto odd ([](int i) {return i % 2 != 0;});

template <typename T>
void quick_remove_at(vector<T> &v, size_t idx){
    if (idx < v.size()){
        v[idx] = move(v.back());
        v.pop_back();
    }
}
template <typename T>
void quick_remove_at(vector<T> &v, typename vector<T>::iterator it){
    if (it != end(v)){
        *it = move(v.back());
        v.pop_back();
    }
}

template <typename T, typename A>
void insert_sorted(T &v, const A &word){
    const auto insert_pos(lower_bound(begin(v), end(v), word));
    v.insert(insert_pos, word);
}

struct billionaire{
        string name;
        double dollars;
        string country;
    };

int main() {
//Удаление элементов из вектора
    vector<int> v {1, 2, 3, 2, 5, 4, 2, 7, 6, 8};
    const auto new_end(remove(begin(v), end(v), 2));
    v.erase(new_end, end(v));
    v.erase(remove_if(begin(v), end(v), odd), end(v));
    v.shrink_to_fit();
    vector<int> v2 {123, 456, 789, 100, 200};
    quick_remove_at(v2, 2);
    quick_remove_at(v2, find(begin(v2), end(v2), 456));

//Получение доступа к элементу вектора
    const size_t container_size {1000};
    vector<int> access (container_size, 123);
    cout << "Out of range element value: "
         << access[container_size + 10] << endl;

    try {
        cout << "Out of range element value: "
             << access.at(container_size + 10) << endl;
    }
    catch (const out_of_range& e){
        cout << "Ooops, out of range access detected: "
             << e.what() << endl;
    }

//Keep sort examples
    vector<string> some_words {"some", "random", "words", "without",
                               "order", "aaa", "yyyy"};
    assert(false == is_sorted(begin(some_words), end(some_words)));
    sort(begin(some_words), end(some_words));
    assert(true == is_sorted(begin(some_words), end(some_words)));
    insert_sorted(some_words, "foobar");
    insert_sorted(some_words, "zzz");
    for (const auto &w : some_words){
        cout << w << " ";
    }
    cout << '\n';

//Insert item to std::map more efficiently and according with conditions
    list<billionaire> billionaires{
            {"Bill Gates",          86.0, "USA"},
            {"Warren Buffet",       75.6, "USA"},
            {"Jeff Bezos",          72.8, "USA"},
            {"Amancio Ortega",      71.3, "Spain"},
            {"Mark Zuckerberg",     56.0, "USA"},
            {"Carlos Slim",         54.5, "Mexico"},
            {"Bernard Arnault",     41.5, "France"},
            {"Liliane Bettencourt", 39.5, "France"},
            {"Wang Jianlin", 31.3, "China"},
            {"Li Ka-shing", 31.2, "Honk Kong"}
    };
    map<string, pair<const billionaire, size_t>> m;
    for (const auto &b : billionaires){
        auto [iterator, success] = m.try_emplace(b.country, b, 1);
        if (!success){
            iterator->second.second += 1;
        }
    }
    for (const auto &[key, value] : m){
        const auto &[b, count] = value;
        cout << b.country << " : " << count
             << "billionaires. Richest is "
             << b.name << " with " << b.dollars
             << "B$\n";
    }



    return 0;
}

















