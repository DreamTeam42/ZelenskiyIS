#encoding "utf8"

StreetW -> 'проспект' | 'проезд' | 'улица' | 'шоссе';
StreetSokr -> 'пр.' | 'просп.' | 'пр-т.' | 'пр-д.' | 'ул.' | 'ш.' | 'пр' | 'просп' | 'пр-т' | 'пр-д' | 'ул' | 'ш';

StreetDescr -> StreetW | StreetSokr;

StreetNameNoun -> (Adj<gnc-agr[1]>) Word<gnc-agr[1],rt> (Word<gram="род">);

NumberW_1 -> AnyWord<wff=/[1-9]?[0-9]-?((ый) | (ой) | (ий) | й)/> {outgram="муж, ед, им"};
NumberW_2 -> AnyWord<wff=/[1-9]?[0-9]-?((ая) | (я) | (яя) | (ья))/> {outgram="жен, ед, им"};
NumberW_3 -> AnyWord<wff=/[1-9]?[0-9]-?((ее) | (ье) | (ое) | е)/> {outgram="сред, ед, им"};

NumberW -> NumberW_1 | NumberW_2 | NumberW_3;

StreetNameAdj -> Adj<h-reg1> Adj*;
StreetNameAdj -> NumberW<gnc-agr[1]> Adj <gnc-agr[1]>;

Street -> StreetDescr interp (Address.Descr) StreetNameNoun<gram="род",h-reg1> interp (Address.StreetName::not_norm);
Street -> StreetDescr interp (Address.Descr) StreetNameNoun<gram="им",h-reg1> interp (Address.StreetName::not_norm);
Street -> StreetNameAdj<gnc-agr[1]> interp (Address.StreetName::not_norm) StreetW<gnc-agr[1]> interp (Address.Descr);
Street -> StreetNameAdj interp (Address.StreetName::not_norm) StreetSokr interp (Address.Descr);
Street -> StreetSokr interp (Address.Descr) StreetNameAdj interp (Address.StreetName::not_norm);
Street -> StreetW<gnc-agr[1]> interp (Address.Descr) StreetNameAdj<gnc-agr[1]> interp (Address.StreetName::not_norm);