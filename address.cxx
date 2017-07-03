#encoding "utf8"

StreetW -> 'проспект' | 'проезд' | 'улица' | 'шоссе';
StreetSokr -> 'пр' | 'просп' | 'пр-т' | 'пр-д' | 'ул' | 'ш';
StreetIm -> 'они'<gram="дат">|'имени';
//SquareDescr -> 'площадь'|'пл';
//SquareW -> 'кв м'|'кв метр'<gram="род">|'м кв'|'квадратные метры'<gram="род">; 

StreetDescr -> StreetW|StreetSokr;

StreetNameNoun -> (Adj<gnc-agr[1]>) Word<gnc-agr[1],rt> (Word<gram="род">);

NumberW_1 -> AnyWord<wff=/[1-9]?[0-9]-?((ый)|(ой)|(ий)|й)/> {outgram="муж,ед,им"};
NumberW_2 -> AnyWord<wff=/[1-9]?[0-9]-?((ая)|(яя)|(ья)|я)/> {outgram="жен,ед,им"};
NumberW_3 -> AnyWord<wff=/[1-9]?[0-9]-?((ее)|(ье)|(ое)|е)/> {outgram="сред,ед,им"};
NumberW_4 -> AnyWord<wff=/[1-9]?[0-9]-?(й|(ой))/> {outgram="жен,ед,род"};

NumberW -> NumberW_1 | NumberW_2 | NumberW_3 | NumberW_4;

StreetNameAdj -> Adj<h-reg1> Adj*;
StreetNameAdj -> NumberW<gnc-agr[1]> Adj<gnc-agr[1]> (Word<gram="род">);

Street -> (StreetDescr <cut>) (StreetIm) StreetNameNoun<gram="род",h-reg1>;
Street -> (StreetDescr <cut>) StreetNameNoun<gram="им",h-reg1>;
Street -> StreetNameAdj<gnc-agr[1]> StreetW<gnc-agr[1],cut>;
Street -> StreetNameAdj StreetSokr<cut>;
Street -> StreetSokr<cut> StreetNameAdj;
Street -> StreetW<gnc-agr[1],cut> StreetNameAdj<gnc-agr[1]>;

Factor -> 'т'|'тыс'|'тысяч'|'миллионов'|'млн';
Currency -> 'рубль'<gram="род">|'р'|'руб';
Value -> Money MoneyW;
Money -> AnyWord<wff=/[1-9]?[0-9]*/>;
MoneyW -> (Factor) Currency;
PriceW -> 'Цена'|'Стоимость'|'ЦЕНА'|'цена'|'СТОИМОСТЬ'|'стоимость';
Price -> PriceW Value;

//CityW -> 'город'|'г'|'гор';
//City -> (CityW) Word<rt>;
//(City interp (Address.City)) (',')

HouseW -> 'д'|'дом';
House -> (HouseW <cut>) AnyWord<wff=/[1-9]?[0-9]?[0-9]?/> (Litera);
Litera -> AnyWord<wff=/[а-яА-Я]/>;

Address -> Street interp (Address.Street::not_norm) (',') House interp (Address.House);
Address -> Price; //Костыль, чтобы цепочки вида "Цена 150 т" не принимались за улицу и дом