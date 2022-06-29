void removeBad(vector<Restaurant*>& v)
{
    // auto will automatically determine the type
    auto it = v.begin();
    while(it != v.end()) {
        Restaurant* temp = *it;
        if (temp->stars() <= 2)
        {
            v.erase(it);
            it = v.begin();
            it--;
            delete temp;
        }
        it++;
    }
}
