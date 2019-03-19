#include <cstdlib>
#include <productid.h>

#include <QtCore/QtDebug>

int main(int argc, char *argv[])
{
    ProductId p1(10);
    qDebug() << "Writing a valid identifier";
    qDebug() << "p1:" << p1.value();
    qDebug() << "p1:" << p1 << '\n';

    ProductId p2;
    qDebug() << "Writing a null identifier";
    qDebug() << "p2:" << p2.value();
    qDebug() << "p2:" << p2 << '\n';

    ProductId p3(20);
    qDebug() << "Writing the identifier using toString()";
    qDebug() << "p3:" << p3.toString() << '\n';

    qDebug() << "Testing two identifiers for equality (p1 == p2)";
    if (p1 == p2)
        qDebug() << "Equal" << '\n';
    else
        qDebug() << "Not equal" << '\n';

    QSet<ProductId> set;
    set << p1;
    set << p2;
    qDebug() << "Writing a set of identifiers";
    qDebug() << set << '\n';

    qDebug() << "Testing the conversion to and from QVariant";
    QVariant v = QVariant::fromValue(p1);
    ProductId p4 = v.value<ProductId>();
    if (p1 == p4)
        qDebug() << "are equal" << '\n';
    else
        qDebug() << "are not equal" << '\n';

    qDebug() << "Testing the int converter from a QVariant";
    if (QMetaType::registerConverter<ProductId, int>(&ProductId::value))
        qDebug() << v.toInt() << '\n';

    qDebug() << "Testing the QString converter from a QVariant";
    if (QMetaType::registerConverter<ProductId, QString>(&ProductId::toString))
        qDebug() << v.toString() << '\n';

    return EXIT_SUCCESS;
}
