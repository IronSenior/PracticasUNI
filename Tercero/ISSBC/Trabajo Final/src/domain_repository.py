import os

from .domain import Domain


from uuid import UUID
import sqlalchemy as db


class DomainRepository:

    def __init__(self):
        self.__db_engine = db.create_engine(os.getenv("DB_ENGINE"))
        self.__db_connection = self.__db_engine.connect()
        self.__db_metadata = db.MetaData()
        self.__domain = db.Table("domains", self.__db_metadata,
                                autoload=True, autoload_with=self.__db_engine)

    def add(self, domain: Domain):
        query = db.insert(self.__domain).values(
                    domain_id=domain.domain_id, 
                    name=domain.name,
                    description=domain.description
                )
        resultProxy = self.__db_connection.execute(query)


    def delete(self, domain: Domain):
        query = db.delete(self.__domain).where(
            self.__domain.columns.domain_id == domain.domain_id)
        resultProxy = self.__db_connection.execute(query)


    def getById(self, domain_id: UUID):
        query = db.select([self.__domain]).where(
            self.__domain.columns.domain_id == domain_id)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None
        return self.__getDomainFromResult(resultSet[0])

    def getByName(self, name):
        query = db.select([self.__domain]).where(
            self.__domain.columns.name == name)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None
        return self.__getDomainFromResult(resultSet[0])

    def getAll(self):
        query = db.select([self.__domain])
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None

        domains = []
        for domain in resultSet:
            domains.append(domain)
        return domains


    def __getDomainFromResult(self, result):
        return Domain(
            domain_id=UUID(result[0]),
            name=result[1],
            description=result[2]
        )



