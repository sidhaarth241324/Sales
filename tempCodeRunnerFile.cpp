string convertDate(const string& date) {
    // Expected format: DD/MM/YYYY
    if (date.size() != 10 || date[2] != '/' || date[5] != '/') return date;
    string yyyy = date.substr(6, 4);
    string mm = date.substr(3, 2);
    string dd = date.substr(0, 2);
    return yyyy + "-" + mm + "-" + dd;