#encoding "utf8"

SquareDescr -> 'площадь'|'Площадь';
SquareW -> Kvadr Meters| Meters Kvadr|'м2';
Kvadr -> 'кв'|'квадратные'<gram="род">|'квадр';
Meters -> 'м'|'метр'<gram="род">;

Square -> (SquareDescr <cut>) AnyWord<wff=/[1-9][0-9]+/> interp (Square.Square) SquareW;
Square -> (SquareDescr <cut>) AnyWord<wff=/[1-9][0-9]+м2/> interp (Square.Square);