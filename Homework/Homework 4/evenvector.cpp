void removeEven(vector<int>& v)
{
    vector<int>::iterator it;
    it = v.begin();
    // while we haven't reached the end of the list
    while(it != v.end()) {
        // if the modulus is 0 then itis even and we can remove it
        if(*it%2 == 0) {
            // remove the element and set the new search to where the iterator currently is
            v.erase(it);
        }
        else {
            // iterate iterator
            it++;
        }
    }
}
