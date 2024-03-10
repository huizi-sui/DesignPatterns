
#pragma once

class AbstractApple {
public:
    virtual void name() = 0;
    virtual ~AbstractApple() = default;
};

class ChinaApple : public AbstractApple {
public:
    void name() override;
    ~ChinaApple() = default;
};

class USAApple : public AbstractApple {
public:
    void name() override;
    ~USAApple() = default;
};

class JapanApple : public AbstractApple {
public:
    void name() override;
    ~JapanApple() = default;
};

class AbstractBanana {
public:
    virtual void name() = 0;
    virtual ~AbstractBanana() = default;
};

class ChinaBanana : public AbstractBanana {
public:
    void name() override;
    ~ChinaBanana() = default;
};

class USABanana : public AbstractBanana {
public:
    void name() override;
    ~USABanana() = default;
};

class JapanBanana : public AbstractBanana {
public:
    void name() override;
    ~JapanBanana() = default;
};

class AbstractFactory {
public:
    virtual AbstractApple* get_apple() = 0;
    virtual AbstractBanana* get_banana() = 0;
    virtual ~AbstractFactory() = default;
};

class ChinaFactory : public AbstractFactory {
public:
    AbstractApple *get_apple() override;
    AbstractBanana *get_banana() override;
    ~ChinaFactory() = default;
};

class USAFactory : public AbstractFactory {
public:
    AbstractApple* get_apple() override;
    AbstractBanana* get_banana() override;
    ~USAFactory() = default;
};

class JapanFactory : public AbstractFactory {
public:
    AbstractApple* get_apple() override;
    AbstractBanana* get_banana() override;
    ~JapanFactory() = default;
};

