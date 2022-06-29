void removeEven(list<int>& li) {
    list<int>::iterator it;
    // set the iterator to the beginning of the list
    it = li.begin();
    // while we haven't reached the end of the list
    while(it != li.end()) {
        // if the modulus is 0 then itis even and we can remove it
        if(*it%2 == 0) {
            // remove the element and set the new search to where the iterator currently is
            li.erase(it);
            it = li.begin();;
        }
        // iterate iterator
        it++;
    }
}
