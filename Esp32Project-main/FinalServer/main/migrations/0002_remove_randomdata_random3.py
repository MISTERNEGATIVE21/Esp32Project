# Generated by Django 4.2.2 on 2023-06-21 11:36

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('main', '0001_initial'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='randomdata',
            name='random3',
        ),
    ]