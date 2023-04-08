from setuptools import find_packages
from setuptools import setup

setup(
    name='ins_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('ins_msgs', 'ins_msgs.*')),
)
