#ifndef SCORES_HPP
#define SCORES_HPP

#include <memory>
#include <iostream>

// a program to implement a Scores class
// The Scores class maintains a list of the highest
// maxEntries scores.

struct Entry {
    std::string name;
    int score;
};

class Scores {
public:
    friend std::ostream& operator<<(std::ostream& out, const Scores& sc);

    explicit Scores(int maxEnt = 10);

    // insert a new Entry
    // if the adding would cause the size to exceed maxEntries, the
    // lowest Entry is removed from the list
    void add(const Entry& e);

    // remove entry at index i
    // throws an out_of_range exception if i not in range [0, maxEntries)
    void remove(int i);

    // returns entry at index i
    Entry get(int i) const;

private:
    int maxEntries_;
    int numEntries_;
    std::unique_ptr<Entry[]> entries_;
};

#endif
