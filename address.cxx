#encoding "utf8"

StreetW -> 'проспект' | 'проезд' | 'улица' | 'шоссе';
StreetSokr -> 'пр' | 'просп' | 'пр-т' | 'пр-д' | 'ул' | 'ш';

StreetDescr -> StreetW | StreetSokr;

StreetNameNoun -> (Adj<gnc-agr[1]>) Word<gnc-agr[1],rt> (Word<gram="род">);

NumberW_1 -> AnyWord<wff=/[1-9]?[0-9]-?((ый)|(ой)|(ий)|й)/> {outgram="муж,ед,им"};
NumberW_2 -> AnyWord<wff=/[1-9]?[0-9]-?((ая)|(яя)|(ья)|я)/> {outgram="жен,ед,им"};
NumberW_3 -> AnyWord<wff=/[1-9]?[0-9]-?((ее)|(ье)|(ое)|е)/> {outgram="сред,ед,им"};
NumberW_4 -> AnyWord<wff=/[1-9]?[0-9]-?(й|(ой))/> {outgram="жен,ед,род"};

NumberW -> NumberW_1 | NumberW_2 | NumberW_3 | NumberW_4;

StreetNameAdj -> Adj<h-reg1> Adj*;
StreetNameAdj -> NumberW<gnc-agr[1]> Adj<gnc-agr[1]> (Word<gram="род">);

Street -> (StreetDescr) StreetNameNoun<gram="род",h-reg1>;
Street -> (StreetDescr) StreetNameNoun<gram="им",h-reg1>;
Street -> StreetNameAdj<gnc-agr[1]> StreetW<gnc-agr[1]>;
Street -> StreetNameAdj StreetSokr;
Street -> StreetSokr StreetNameAdj;
Street -> StreetW<gnc-agr[1]> StreetNameAdj<gnc-agr[1]>;

CityW -> 'город'|'г'|'гор';
City -> (CityW) Word<rt>;

HouseW -> 'д'|'дом';
House -> (HouseW) AnyWord<wff=/[1-9]?[0-9]?[0-9]?/>;

Address -> (City interp (Address.City)) (',') Street interp (Address.Street) (',') House interp (Address.House);