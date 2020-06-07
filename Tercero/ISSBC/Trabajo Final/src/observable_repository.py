import os

from .observable import Observable


from uuid import UUID
import sqlalchemy as db


class ObservableRepository:

    def __init__(self):
        self.__db_engine = db.create_engine(os.getenv('DB_ENGINE'))
        self.__db_connection = self.__db_engine.connect()
        self.__db_metadata = db.MetaData()
        self.__observables = db.Table("observables", self.__db_metadata,
                                autoload=True, autoload_with=self.__db_engine)

    def add(self, observable: Observable):
        query = db.insert(self.__observables).values(
                    observable_id=observable.observable_id, 
                    domain_id=observable.domain_id,
                    name=observable.name,
                    description=observable.description,
                    value_type=observable.value_type
                )
        resultProxy = self.__db_connection.execute(query)


    def delete(self, observable: Observable):
        query = db.delete(self.__observables).where(
            self.__observables.columns.observable_id == observable.observable_id)
        resultProxy = self.__db_connection.execute(query)


    def getById(self, observable_id: UUID):
        query = db.select([self.__observables]).where(
            self.__observables.columns.observable_id == observable_id)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None
        return self.__getObservableFromResult(resultSet[0])


    def getByName(self, name):
        query = db.select([self.__observables]).where(
            self.__observables.columns.name == name)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None
        return self.__getObservableFromResult(resultSet[0])


    def getByDomain(self, domain_id: UUID):
        query = db.select([self.__observables]).where(
            self.__observables.columns.domain_id == domain_id)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None

        hypothesis = []
        for result in resultSet:
            hypothesis.append(self.__getObservableFromResult(result))
        return hypothesis


    def __getObservableFromResult(self, result: tuple):
        return Observable(
            observable_id = UUID(result[0]),
            domain_id = result[1],
            name = result[2],
            description = result[3],
            value_type = result[4]
        )