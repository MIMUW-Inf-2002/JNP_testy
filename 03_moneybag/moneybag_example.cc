#include <cassert>
#include <iostream>
#include <string>
#include "moneybag.h"

using namespace std;

int main() {
    // Taka konstrukcja nie powinna się kompilować.
    // Moneybag m0;

    Moneybag m1 = Moneybag(1, 10, 19);
    Moneybag m2 = 2 * Solidus + 17 * Denier;
    Moneybag m3(0, 0, 0);
    Moneybag m4(m1);
    m4 = m3;

    cout << m3 << endl;
    cout << m4 + m2 - Solidus << endl;

    Moneybag::coin_number_t s = m2.solidus_number();
    assert(s == 2);

    assert(m1);
    assert(!m3);
    assert(m1 >= m2);
    assert(m1 > m2);
    assert(!(m1 < m2));
    assert(m4 == m3);

    assert(Moneybag(2, 2, 1) >= Moneybag(2, 1, 1));
    assert(Moneybag(2, 2, 1) > Moneybag(2, 1, 1));
    assert(!(Moneybag(1, 2, 2) <= Moneybag(2, 2, 1)));
    assert(!(Moneybag(1, 2, 2) < Moneybag(2, 2, 1)));

    m2 += 28 * Solidus + 2 * Denier;

    cout << m1 << endl;
    cout << m2 << endl;

    assert(!(m1 == m2));
    assert(!(m1 > m2));
    assert(!(m1 < m2));

    Value v1 = Value(m1);
    Value v2(m2);

    cout << static_cast<string>(v1) << endl;
    cout << string(Value(Livre)) << endl;

    assert(v1 == v2);
    assert(!is_neq(v1 <=> v2));
    assert(v1 == 379);
    assert(379 == v2);
    assert(v1 > 350);
    assert(350 < v2);
    assert(0 == Value());

    // Te konstrukcje nie powinny się kompilować.
    // Livre = Denier;
    // Denier = Solidus;
    // Solidus = Livre;
    // int k = Moneybag(1, 2, 3);
}
