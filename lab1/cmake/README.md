Подсчет суммы синусов для float- и double-значений.

# Сборка

## Double

```
    mkdir build
    cd build
    cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-11 -DUSE_DOUBLE=ON ..
    make
```

## Float

```
    mkdir build
    cd build
    cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-11 -DUSE_DOUBLE=OFF ..
    make
```

# Запуск

```
    ./lab1
```

# Вычисленные значения сумм

```
    double: 0.00000000004895819654503
    float: -0.02778621949255466461182
```