// example.h
#pragma once

class Example {
public:
    Example(int initialValue);
    void setValue(int value);
    int getValue() const;
private:
    int value;
};
