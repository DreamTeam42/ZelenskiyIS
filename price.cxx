#encoding "utf8"

Factor -> 'т'|'тыс'|'тысяч'|'миллионов'|'млн'|'тысячи'|'к';
Currency -> 'рубль'<gram="род">|'р'|'руб';
Value -> Money MoneyW;
Money -> AnyWord<wff=/[1-9][0-9]*(т|млн)?/>;
MoneyW -> (Factor) Currency;
PriceW -> 'Цена'|'Стоимость'|'ЦЕНА'|'цена'|'СТОИМОСТЬ'|'стоимость';

Price -> (PriceW <cut>) Value interp (Price.Price);
Price -> AnyWord<wff=/[1-9][0-9]*(руб|р|рублей|т|тр|млн|к)/> interp (Price.Price); 