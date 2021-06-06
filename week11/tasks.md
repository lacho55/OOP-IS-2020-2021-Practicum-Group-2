# Практикум ООП седмица 11


## Задача 1
## Да се реализира йерархия от класове, която описва средства за писане.
<h3>
Базов клас за йерархията да бъде **Пишещо средство (WritingInstrument)**. Всяко такова трябва да има марка (символен низ с произволна дължина) и година на производство (цяло неотрицателно число).

Наследници на класа трябва да бъдат **Маркер (Marker)**, който има и цвят (символен низ с произволна дължина) и **Молив (Pencil)**, който има твърдост (цяло число между 0 и 14).

За всеки от класовете да се реализират:

- Голямата четворка (там където е нужна);
- Подходящи Get/Set функции за член-данните на класовете;
- operator<< за изход в поток;
- operator>> за вход от поток.

</h3> 


## Задача 2
<h3>
Да се реализират:

абстрактен базов клас Device, описващ техническo устройствo, който съдържа производител (низ с произволна дължина) и поддържа две операции:
* print: за извеждане на информация за устройство; 
* get_perf: за намиране на числова мярка за производителност на устройството;

производен клас Laptop, описващ лаптоп, който има допълнителна член-данна за скорост (цяло число мегахерци). 
Да се дефинират двете операции print и get_perf, като:
* информацията за лаптопа се състои от неговия производител и скорост;
* мярката за производителност на лаптопа е неговата скорост;

производен клас Car, описващ автомобил, който има допълнителни член-данни за мощност (цяло число киловати) и обем на двигателя (цяло число cm3). Да се дефинират двете операции print и get_perf, като:
 * информацията за автомобила се състои от неговия производител, мощност и обем;
 * мярката за производителност на автомобила е неговата мощност;
клас Inventory, описващ фирмен инвентар от устройства (до 100 на брой), които могат да бъдат лаптопи и коли. Да се реализират:
функция, която извежда информация за всички устройства в списъка;
функция, която проверява дали инвентарът е подреден в нарастващ ред по производителност.

Забележка: реализирайте методите от голямата четворка само когато се налага, т.е. когато системно генерираната голяма четворка не върши работа.
</h3>