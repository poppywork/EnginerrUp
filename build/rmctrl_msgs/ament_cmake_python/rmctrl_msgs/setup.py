from setuptools import find_packages
from setuptools import setup

setup(
    name='rmctrl_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('rmctrl_msgs', 'rmctrl_msgs.*')),
)
