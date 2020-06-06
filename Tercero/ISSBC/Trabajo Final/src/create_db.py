import sqlalchemy as db
import os
from uuid import UUID

from dotenv import load_dotenv

load_dotenv()

engine = db.create_engine(os.getenv("DB_ENGINE"))
connection = engine.connect()
metadata = db.MetaData()

def remove_existing_tables():
    sql = 'DROP TABLE IF EXISTS domains;DROP TABLE IF EXISTS observables;DROP TABLE IF EXISTS hypothesis;DROP TABLE IF EXISTS hypo_observables;'
    result = engine.execute(sql)

def create_domain_table():
    users = db.Table('domains', metadata,
                db.Column('domain_id', db.String(255), nullable=False, primary_key=True),
                db.Column('name', db.String(255), nullable=False),
                db.Column('description', db.String(255), nullable=False)
            )

def create_hypothesis_table():
    users = db.Table('hypothesis', metadata,
                db.Column('hypothesis_id', db.String(36), nullable=False, primary_key=True),
                db.Column('domain_id', db.String(255), nullable=False),
                db.Column('name', db.String(255), nullable=False),
                db.Column('description', db.String(255), nullable=False)
            )

def create_observables_table():
    followed_movies = db.Table('observables', metadata,
                db.Column('observable_id', db.String(36), nullable=False, primary_key=True),
                db.Column('domain_id', db.String(36), nullable=False),
                db.Column('name', db.String(255), nullable=False),
                db.Column('description', db.String(255), nullable=False),
                db.Column('value_type', db.String(255), nullable=False)
            )

def create_hypo_observables_table():
    watched_movies = db.Table('hypo_observables', metadata,
                db.Column('hypothesis_id', db.String(36), nullable=False, primary_key=True),
                db.Column('observable_id', db.String(36), nullable=False, primary_key=True),
                db.Column('value', db.String(255), nullable=False),
            )

if __name__ == "__main__":
    remove_existing_tables()

    metadata.create_all(engine)