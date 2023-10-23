#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    struct Type
    {
        LL sz, len;
        std::unordered_map<std::string, int> son_id;
        std::vector<std::pair<Type *, std::string>> son;
        bool isBasic();
        std::string findName(LL pos);
        LL findAddr(std::string type);
    };
    struct Var
    {
        LL addr;
        Type *tp;
        std::string name;
        std::string findName(LL pos);
        LL findAddr(std::string type);
    };
    bool Type::isBasic()
    {
        return this->son.empty();
    }
    std::string Type::findName(LL pos)
    {
        LL now = 0;
        for (auto &i : son)
        {
            now = std::ceil((double)now / i.first->len) * i.first->len;
            if (0 <= pos - now && pos - now < i.first->sz)
            {
                if (i.first->isBasic())
                {
                    return i.second;
                }
                else
                {
                    std::string res = i.first->findName(pos - now);
                    if (res == "ERR")
                    {
                        return "ERR";
                    }
                    else
                    {
                        return i.second + '.' + res;
                    }
                }
            }
            now += i.first->sz;
        }
        return "ERR";
    }
    LL Type::findAddr(std::string type)
    {
        LL res = 0;
        if (type.find('.') == std::string::npos)
        {
            for (int i = 0; i < son_id[type]; i++)
            {
                res = std::ceil((double)res / son[i].first->len) * son[i].first->len;
                res += son[i].first->sz;
            }
            res = std::ceil((double)res / son[son_id[type]].first->len) * son[son_id[type]].first->len;
            return res;
        }
        for (int i = 0; i < son_id[type.substr(0, type.find('.'))]; i++)
        {
            res = std::ceil((double)res / son[i].first->len) * son[i].first->len;
            res += son[i].first->sz;
        }
        res = std::ceil((double)res / son[son_id[type.substr(0, type.find('.'))]].first->len) * son[son_id[type.substr(0, type.find('.'))]].first->len;
        return res + son[son_id[type.substr(0, type.find('.'))]].first->findAddr(type.substr(type.find('.') + 1, type.size() - type.find('.') - 1));
    }
    std::string Var::findName(LL pos)
    {
        std::string res;
        if (this->tp->isBasic())
        {
            if (pos >= this->tp->sz)
            {
                return "ERR";
            }
            return this->name;
        }
        else
        {
            res = this->tp->findName(pos);
        }
        if (res == "ERR")
        {
            return "ERR";
        }
        return name + '.' + res;
    }
    LL Var::findAddr(std::string type)
    {
        return this->addr + tp->findAddr(type);
    }
    int n;
    LL max_addr;
    std::vector<Var *> var;
    std::vector<Type *> type;
    std::unordered_map<std::string, Var *> var_id;
    std::unordered_map<std::string, Type *> type_id;
    void init()
    {
        Type *Byte = new Type(), *Short = new Type(), *Int = new Type(), *Long = new Type();
        Byte->sz = Byte->len = 1;
        Short->sz = Short->len = 2;
        Int->sz = Int->len = 4;
        Long->sz = Long->len = 8;
        type.push_back(Byte), type.push_back(Short), type.push_back(Int), type.push_back(Long);
        type_id["byte"] = Byte, type_id["short"] = Short, type_id["int"] = Int, type_id["long"] = Long;
    }
    void insertType(std::string name, std::vector<std::pair<std::string, std::string>> son)
    {
        int cnt = 0;
        Type *new_type = new Type();
        for (auto &i : son)
        {
            new_type->son.push_back(std::make_pair(type_id[i.first], i.second));
            new_type->son_id[i.second] = cnt++;
            new_type->len = std::max(new_type->len, type_id[i.first]->len);
            new_type->sz = std::ceil((double)new_type->sz / type_id[i.first]->len) * type_id[i.first]->len;
            new_type->sz += type_id[i.first]->sz;
        }
        new_type->sz = std::ceil((double)new_type->sz / new_type->len) * new_type->len;
        type.push_back(new_type), type_id[name] = new_type;
    }
    void insertVar(std::string name, std::string tp)
    {
        Var *new_var = new Var();
        max_addr = std::ceil((double)max_addr / type_id[tp]->len) * type_id[tp]->len;
        new_var->name = name, new_var->addr = max_addr, new_var->tp = type_id[tp];
        max_addr += type_id[tp]->sz;
        var.push_back(new_var), var_id[name] = new_var;
    }
    std::string findName(LL pos)
    {
        for (auto &v : var)
        {
            if (v->addr <= pos && pos < v->addr + v->tp->sz)
            {
                return v->findName(pos - v->addr);
            }
        }
        return "ERR";
    }
    LL findAddr(std::string type)
    {
        if (type.find('.') == std::string::npos)
        {
            return var_id[type]->addr;
        }
        return var_id[type.substr(0, type.find('.'))]->findAddr(type.substr(type.find('.') + 1, type.size() - type.find('.') - 1));
    }
    int main()
    {
        init();
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int op;
            std::cin >> op;
            if (op == 1)
            {
                int k;
                std::string name;
                std::vector<std::pair<std::string, std::string>> son;
                std::cin >> name >> k;
                for (int j = 1; j <= k; j++)
                {
                    std::string s1, s2;
                    std::cin >> s1 >> s2;
                    son.push_back(std::make_pair(s1, s2));
                }
                insertType(name, son);
                std::cout << type_id[name]->sz << " " << type_id[name]->len << std::endl;
            }
            if (op == 2)
            {
                std::string tp, name;
                std::cin >> tp >> name;
                insertVar(name, tp);
                std::cout << var_id[name]->addr << std::endl;
            }
            if (op == 3)
            {
                std::string name;
                std::cin >> name;
                std::cout << findAddr(name) << std::endl;
            }
            if (op == 4)
            {
                LL addr;
                std::cin >> addr;
                std::cout << findName(addr) << std::endl;
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}