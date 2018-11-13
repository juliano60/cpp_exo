#include "Scores.hpp"
#include <stdexcept>

Scores::Scores(int maxEnt):
    maxEntries_{maxEnt},
    numEntries_{0},
    entries_{new Entry[maxEnt]}
{}

void Scores::add(const Entry& e) {
    if (numEntries_ == maxEntries_) {
        // highest maxEntries_ already in the list
        if (e.score <= entries_[maxEntries_ - 1].score) {
            return;
        }
    }
    else {
        ++numEntries_;
    }

    // shift lower Entries up by one
    int i = numEntries_ - 2;
    while (i >= 0 && e.score > entries_[i].score) {
        entries_[i+1] = entries_[i];
        --i;
    }

    entries_[i+1] = e;
}

void Scores::remove(int i) {
    if (i < 0 || numEntries_ <= i) {
        throw std::out_of_range{"remove() - index invalid"};
    }

    for (int j = i+1; j < numEntries_; ++j) {
        entries_[j-1] = entries_[j];
    }
    --numEntries_;
}

Entry Scores::get(int i) const {
    if (i < 0 || numEntries_ <= i) {
        throw std::out_of_range{"get() - index invalid"};
    }

    return entries_[i];
}

std::ostream& operator<<(std::ostream& out, const Scores& sc) {
    out << "[";
    for (int i = 0; i != sc.numEntries_; ++i) {
        std::cout << sc.entries_[i].score;
        if (i < sc.numEntries_ - 1) {
            out << " ";
        }
    }
    out << "]";

    return out;
}
 
