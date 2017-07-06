#encoding "utf8"

Phone -> AnyWord<wff=/((8|\+7)[\- ]?)?(\(?\d{3}\)?[\- ]?)?[\d\- ]{7,10}/> interp (Contacts.Phone);