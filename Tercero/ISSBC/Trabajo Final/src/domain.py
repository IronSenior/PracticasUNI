

class Domain:

    def __init__(self, domain_id, name, description):
        self.__domain_id = domain_id
        self.__name = name
        self.__description = description

    
    @property
    def domain_id(self):
        return self.__domain_id

    @property
    def name(self):
        return self.__name

    @property
    def description(self):
        return self.__description

