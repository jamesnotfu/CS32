void listAll(const Domain* d, string path) // two-parameter overload
{
    // base case
    if(d->subdomains().size() == 0) {
        cout << path << endl;
        return;
    }
    else if(path != "") {
        path = "." + path;
    }
    // recursive call
    // use auto to work for multiple types
    auto it = d->subdomains().begin();
    while(it != d->subdomains().end()) {
        listAll(*it, (*it)->label() + path);
        it++;
    }
}
