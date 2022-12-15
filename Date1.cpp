#include"Date1.h"
Date::Date() {
    time_t t = std::time(0);
    tm* now = std::localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}
Date::Date(int day, int month, int year) :day(day), month(month), year(year) {

}
Date::~Date() {

}
string Date::getYear() {
    string k = to_string(year);
    return k;
}
string Date::getMonth() {
    string k = to_string(month);
    return k;
}
string Date::getDay() {
    string k = to_string(day);
    return k;
}
string Date::getDate() {
    return getDay() + "/" + getMonth() + "/" + getYear();
    
}