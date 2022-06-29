void removeBad(list<Restaurant*>& li) {
    // auto will automatically determine the type
    auto it = li.begin();
    while(it != li.end()) {
        Restaurant* temp = *it;
        if (temp->stars() <= 2)
        {
            li.erase(it);
            it = li.begin();
            it--;
            // delete temp otherwise floating memory
            delete temp;
        }
        it++;
    }
}
