
value_type_dict = {
    "Integer": int,
    "Boolean": bool,
    "String": str
}

class Observable:

    def __init__(self, observable_id, domain_id, name, description, value_type):
        self.__observable_id = observable_id
        self.__domain_id = domain_id
        self.__name = name
        self.__description = description
        self.__value_type = value_type
        self.__value = None

    def setValue(self, value):
        if not self.__isPermitedValue(value):
            raise Exception("Not Permited Value")
        self.__value = value

    def __isPermitedValue(self, value):
        if not type(value) == value_type_dict[self.__value_type]:
            return False
        return True

    @staticmethod
    def withValue(domain_id, name, description, value_type, value):
        observable = Observable(domain_id, name, description, value_type)
        observable.setValue(value)
        return observable

    @property
    def observable_id(self):
        return self.__observable_id
    
    @property
    def domain_id(self):
        return self.__domain_id

    @property
    def name(self):
        return self.__name
    
    @property 
    def description(self):
        return self.__description

    @property
    def value(self):
        return self.__value
    
    @property
    def value_type(self):
        return self.__value_type

    def __eq__(self, other):
        if not other.value_type == self.__value_type:
            return False
        if not other.observable_id == self.__observable_id:
            return False
        return self.value == other.value
        

    