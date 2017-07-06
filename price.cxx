#encoding "utf8"

Factor -> 'т'|'тыс'|'тысяч'|'миллионов'|'млн'|'тысячи';
Currency -> 'рубль'<gram="род">|'р'|'руб';
Value -> Money MoneyW;
Money -> AnyWord<wff=/[1-9]?[0-9]*/>;
MoneyW -> (Factor) Currency;
PriceW -> 'Цена'|'Стоимость'|'ЦЕНА'|'цена'|'СТОИМОСТЬ'|'стоимость';

Price -> (PriceW <cut>) Value interp (Price.Price);